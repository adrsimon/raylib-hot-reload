cmake_minimum_required(VERSION 3.10)
project(raylib-hot-reload)

# Déclaration de l'exécutable
add_executable(raylib-hot-reload main.c)

# Chemin vers les fichiers d'en-tête de Raylib
include_directories(${CMAKE_SOURCE_DIR}/raylib/include)

# Chemin vers les bibliothèques de Raylib
link_directories(${CMAKE_SOURCE_DIR}/raylib/lib)

# Configuration pour trouver la bibliothèque Raylib
target_link_libraries(raylib-hot-reload raylib)

# Options de compilation
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Générer le fichier compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

