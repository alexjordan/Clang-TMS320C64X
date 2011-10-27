//===----------------------------------------------------------------------===//
// C Language Family Front-end
//===----------------------------------------------------------------------===//

Welcome to Clang.  This is a compiler front-end for the C family of languages
(C, C++, Objective-C, and Objective-C++) which is built as part of the LLVM
compiler infrastructure project.

Unlike many other compiler frontends, Clang is useful for a number of things
beyond just compiling code: we intend for Clang to be host to a number of
different source level tools.  One example of this is the Clang Static Analyzer.

If you're interested in more (including how to build Clang) it is best to read
the relevant web sites.  Here are some pointers:

Information on Clang:              http://clang.llvm.org/
Building and using Clang:          http://clang.llvm.org/get_started.html
Clang Static Analyzer:             http://clang-analyzer.llvm.org/
Information on the LLVM project:   http://llvm.org/

If you have questions or comments about Clang, a great place to discuss them is
on the Clang development mailing list:
  http://lists.cs.uiuc.edu/mailman/listinfo/cfe-dev

If you find a bug in Clang, please file it in the LLVM bug tracker:
  http://llvm.org/bugs/

--------------------------------

This branch contains modifications for using Clang as a frontend for the TI
C64x+ VLIW processor.

It is based on the initial contribution by Jeremy Morse[1], available at
git.srobo.org.

Maintained by members of the EPICOpt[2] team, at the Vienna University of
Technology.

--------------------------------

[1] http://permalink.gmane.org/gmane.comp.compilers.llvm.devel/33870
[2] http://www.complang.tuwien.ac.at/epicopt/

