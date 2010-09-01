// Test is line- and column-sensitive. See run lines below.

template<typename T, T Value, template<typename U, U ValU> class X>
void f(X<T, Value> x);

template<typename T> class allocator;

template<typename T, typename Alloc = allocator<T> >
class vector {
};

template<typename T>
class vector<T*> { };

// RUN: c-index-test -test-load-source all %s | FileCheck -check-prefix=CHECK-LOAD %s
// CHECK-LOAD: index-templates.cpp:4:6: FunctionTemplate=f:4:6 Extent=[3:1 - 4:22]
// CHECK-LOAD: index-templates.cpp:3:19: TemplateTypeParameter=T:3:19 (Definition) Extent=[3:19 - 3:20]
// CHECK-LOAD: index-templates.cpp:3:24: NonTypeTemplateParameter=Value:3:24 (Definition) Extent=[3:22 - 3:29]
// FIXME: Need the template type parameter here
// CHECK-LOAD: index-templates.cpp:3:66: TemplateTemplateParameter=X:3:66 (Definition) Extent=[3:31 - 3:67]
// CHECK-LOAD: index-templates.cpp:4:20: ParmDecl=x:4:20 (Definition) Extent=[4:8 - 4:21]
// CHECK-LOAD: index-templates.cpp:4:8: TemplateRef=X:3:66 Extent=[4:8 - 4:9]
// FIXME: Need the template type parameter here
// CHECK-LOAD: index-templates.cpp:4:13: DeclRefExpr=Value:3:24 Extent=[4:13 - 4:18]
// CHECK-LOAD: index-templates.cpp:6:28: ClassTemplate=allocator:6:28 Extent=[6:1 - 6:37]
// CHECK-LOAD: index-templates.cpp:6:19: TemplateTypeParameter=T:6:19 (Definition) Extent=[6:19 - 6:20]
// CHECK-LOAD: index-templates.cpp:9:7: ClassTemplate=vector:9:7 (Definition) Extent=[8:1 - 10:2]
// CHECK-LOAD: index-templates.cpp:8:19: TemplateTypeParameter=T:8:19 (Definition) Extent=[8:19 - 8:20]
// CHECK-LOAD: index-templates.cpp:8:31: TemplateTypeParameter=Alloc:8:31 (Definition) Extent=[8:31 - 8:36]
// CHECK-LOAD: index-templates.cpp:13:7: ClassTemplatePartialSpecialization=vector:13:7 (Definition) Extent=[12:1 - 13:21]
// CHECK-LOAD: index-templates.cpp:12:19: TemplateTypeParameter=T:12:19 (Definition) Extent=[12:19 - 12:20]
// FIXME: Need the template type parameter here

// RUN: c-index-test -test-load-source-usrs all %s | FileCheck -check-prefix=CHECK-USRS %s
// CHECK-USRS: index-templates.cpp c:@FT@>3#T#Nt0.0#t>2#T#Nt1.0f#>t0.22t0.0# Extent=[3:1 - 4:22]
// CHECK-USRS: index-templates.cpp c:index-templates.cpp@79 Extent=[3:19 - 3:20]
// CHECK-USRS: index-templates.cpp c:index-templates.cpp@82 Extent=[3:22 - 3:29]
// CHECK-USRS: index-templates.cpp c:index-templates.cpp@91 Extent=[3:31 - 3:67]
// CHECK-USRS: index-templates.cpp c:index-templates.cpp@136@FT@>3#T#Nt0.0#t>2#T#Nt1.0f#>t0.22t0.0#@x Extent=[4:8 - 4:21]
// CHECK-USRS: index-templates.cpp c:@CT>1#T@allocator Extent=[6:1 - 6:37]
// CHECK-USRS: index-templates.cpp c:index-templates.cpp@171 Extent=[6:19 - 6:20]
// CHECK-USRS: index-templates.cpp c:@CT>2#T#T@vector Extent=[8:1 - 10:2]
// CHECK-USRS: index-templates.cpp c:index-templates.cpp@264@CP>1#T@vector Extent=[12:1 - 13:21]
// CHECK-USRS: index-templates.cpp c:index-templates.cpp@282 Extent=[12:19 - 12:20]