project(nutils)

add_library(nutils SHARED observable.cpp )

install(TARGETS nutils LIBRARY DESTINATION lib)
install(FILES observable.h DESTINATION include/NUtils)
