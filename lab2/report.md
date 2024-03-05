% Лабораторная работа № 2.1. Синтаксические деревья
% 21 февраля 2023 г.
% Марченко Андрей, ИУ9-62Б

# Цель работы
Целью данной работы является изучение представления синтаксических деревьев в памяти компилятора 
и приобретение навыков преобразования синтаксических деревьев.

# Индивидуальный вариант
Разбить блоки объявления нескольких переменных на несколько блоков объявления одной переменной.

# Реализация

Демонстрационная программа:

```go
package test

import "fmt"

var q, w string
var z, y bool

func sum(a, b int) {
	var e, t int
	fmt.Println(e + t + a + b)
}

func main() {
    fmt.Println("da")
	var gt int
	var a, d, b int
	var nm string

	for i := 0; i < 10; i++ {
		var l, m int
		fmt.Println(l, m)
	}

    sum(a, b)
	fmt.Println(d, gt, nm, q, w, z, y)
}

```

Программа, осуществляющая преобразование синтаксического дерева:

```go
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
					var newvars []ast.Stmt
					if genDecl.Tok == token.VAR {
						for _, spec := range genDecl.Specs {
							valueSpec := spec.(*ast.ValueSpec)
							if len(valueSpec.Names) > 1 {
								shift = len(valueSpec.Names)
								for j, _ := range valueSpec.Names {
									var idents []*ast.Ident
									idents = append(idents, valueSpec.Names[j])
									newvars = append(newvars, []ast.Stmt{&ast.DeclStmt{
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
									}}...)
								}
							}
						}
					}
					if shift != 0 {
						blockStmt.List = append(blockStmt.List[:i], append(newvars, blockStmt.List[i+1:]...)...)
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
					var newvars []ast.Decl
					if genDecl.Tok == token.VAR {
						for _, spec := range genDecl.Specs {
							valueSpec := spec.(*ast.ValueSpec)
							if len(valueSpec.Names) > 1 {
								shift = len(valueSpec.Names)
								for j, _ := range valueSpec.Names {
									var idents []*ast.Ident
									idents = append(idents, valueSpec.Names[j])
									newvars = append(newvars, &ast.GenDecl{
										Tok: token.VAR,
										Specs: []ast.Spec{
											&ast.ValueSpec{
												Names:  idents,
												Type:   valueSpec.Type,
												Values: valueSpec.Values,
											},
										},
									})
								}
							}
						}
					}
					if shift != 0 {
						astFile.Decls = append(astFile.Decls[:i], append(newvars, astFile.Decls[i+1:]...)...)
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
		if format.Node(writer, fset, file) != nil {
			fmt.Printf("Formatter error: %v\n", err)
		}
		ast.Fprint(os.Stdout, fset, file, nil)
	} else {
		fmt.Printf("Errors in %s\n", os.Args[1])
	}
}

```

# Тестирование

Результат трансформации демонстрационной программы:

```go
package test

import "fmt"

var q string
var w string
var z bool
var y bool

func sum(a, b int) {
	var e int
	var t int
	fmt.Println(e + t + a + b)
}

func main() {
	fmt.Println("da")
	var gt int
	var a int
	var d int
	var b int
	var nm string

	for i := 0; i < 10; i++ {
		var l int
		var m int
		fmt.Println(l, m)
	}

	sum(a, b)
	fmt.Println(d, gt, nm, q, w, z, y)
}

```

# Вывод
В этой лабораторной работе мною были получены навыки работы с синтаксическими деревьями на языке Golang, 
их преобразованиями и представлениями. 
Для успешного выполнения моего варианта мне пришлось изучить структуру такого дерева, 
а именно как распложены и какую структуру имеют блоки var в функциях и в начале программы, 
какие у них родительские вершины и как я должен создавать новые определения переменных. 
В целом, лабораторная работа показалась мне интересной и полезной.