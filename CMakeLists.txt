project(nutils)

add_library(nutils SHARED observable.cpp vector.cpp)

install(TARGETS nutils LIBRARY DESTINATION lib)
install(FILES observable.h vector.h DESTINATION include/NUtils)
