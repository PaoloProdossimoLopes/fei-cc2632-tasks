cmake_minimum_required(VERSION 3.26)
project(tasks C)

set(CMAKE_C_STANDARD 11)

add_executable(tasks main.c
        models/task/Task.h
        models/task/Task.c
        helpers/helpers.h
        helpers/helpers.c
        core/create/create_task.h
        core/create/create_task.c
        core/list/list_task.h
        core/list/list_tasks.c)
