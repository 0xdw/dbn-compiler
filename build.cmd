@echo off
echo Building compiler...
del /f dbn.exe dbn.ilk dbn.pdb
cmd /c g++ -g -std=c++11 res/resource.res src/main.cc src/utils.cc src/constants.cc src/syntax_analyzer.cc src/file.cc src/exception.cc src/lexer.cc src/transformer.cc src/code_generator.cc src/code_optimizer.cc src/parser.cc src/compiler.cc -o dbn
echo Build successful.
@echo on
cmd /c dbn compile samples/triangle.dbn samples/triangle.svg