idf_component_register(SRCS "main.cpp" "model_settings.cpp" "person_detect_model_data.cpp" 
                    INCLUDE_DIRS  "./")

component_compile_options(-std=c++11)
