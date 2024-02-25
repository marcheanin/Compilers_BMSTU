package main

import (
	"fmt"
	"go/ast"
	"go/format"
	"go/parser"
	//"go/printer"
	"go/token"
	"os"
)

func divideVar(file *ast.File) {
	ast.Inspect(file, func(node ast.Node) bool {
		if blockStmt, ok := node.(*ast.BlockStmt); ok {
			for i, elem := range blockStmt.List {
				switch elem.(type) {
				case *ast.DeclStmt:
					shift := 0
					genDecl := blockStmt.List[i].(*ast.DeclStmt).Decl.(*ast.GenDecl)
					if genDecl.Tok == token.VAR {
						for _, spec := range genDecl.Specs {
							valueSpec := spec.(*ast.ValueSpec)
							if len(valueSpec.Names) > 1 {
								shift = len(valueSpec.Names)
								for j, name := range valueSpec.Names {
									var idents []*ast.Ident
									idents = append(idents, valueSpec.Names[j])
									fmt.Printf("var %s %s\n", name, valueSpec.Type)
									blockStmt.List = append([]ast.Stmt{&ast.DeclStmt{
										Decl: &ast.GenDecl{
											Tok: token.VAR,
											Specs: []ast.Spec{
												&ast.ValueSpec{
													Names:  idents,
													Type:   valueSpec.Type,
													Values: valueSpec.Values,
												},
											},
										},
									}}, blockStmt.List...)
								}
							}
						}
					}
					if shift != 0 {
						blockStmt.List = append(blockStmt.List[:i+shift], blockStmt.List[i+1+shift:]...)
						i--
					}
				}
			}
		}
		if astFile, ok := node.(*ast.File); ok {
			for i, elem := range astFile.Decls {
				switch elem.(type) {
				case *ast.GenDecl:
					shift := 0
					genDecl := elem.(*ast.GenDecl)
					if genDecl.Tok == token.VAR {
						for _, spec := range genDecl.Specs {
							valueSpec := spec.(*ast.ValueSpec)
							if len(valueSpec.Names) > 1 {
								shift = len(valueSpec.Names)
								for j, name := range valueSpec.Names {
									var idents []*ast.Ident
									idents = append(idents, valueSpec.Names[j])
									fmt.Printf("var %s %s\n", name, valueSpec.Type)
									astFile.Decls = append(
										[]ast.Decl{&ast.GenDecl{
											Tok: token.VAR,
											Specs: []ast.Spec{
												&ast.ValueSpec{
													Names:  idents,
													Type:   valueSpec.Type,
													Values: valueSpec.Values,
												},
											},
										}},
										astFile.Decls...)
								}
							}
						}
					}
					if shift != 0 {
						astFile.Decls = append(astFile.Decls[:i+shift], astFile.Decls[i+1+shift:]...)
						i--
					}
				}
			}
		}
		return true
	})

}

func main() {
	if len(os.Args) != 2 {
		return
	}

	fset := token.NewFileSet()
	if file, err := parser.ParseFile(fset, os.Args[1], nil, parser.ParseComments); err == nil {
		divideVar(file)
		writer, err := os.OpenFile("test_rebuild.go", os.O_CREATE|os.O_RDWR, 0777)
		defer writer.Close()
		if format.Node(os.Stdout, fset, file) != nil {
			fmt.Printf("Formatter error: %v\n", err)
		}
		ast.Fprint(os.Stdout, fset, file, nil)
	} else {
		fmt.Printf("Errors in %s\n", os.Args[1])
	}
}
