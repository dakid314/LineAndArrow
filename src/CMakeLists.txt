project(SDK_Package)

add_subdirectory(SDK)

# find_library(SDK_Core REQUIRED)
# find_library(SDK_Drawer REQUIRED)
# find_library(SDK_Dataloader REQUIRED)

add_executable(LineArrowAndCirco main.cpp)
target_link_libraries(LineArrowAndCirco SDK_Core SDK_Drawer SDK_Dataloader)