cmake_minimum_required(VERSION 3.21)
project(C C)

set(CMAKE_C_STANDARD 11)

add_executable(C
        EjerciciosClase/AlgoritmoPeterson/peterson.c
        EjerciciosClase/DescriptoresFichero/descriptores.c
        EjerciciosClase/EjempleExec/ejemploExec.c
        EjerciciosClase/EjemploSigterm/ejemploSigterm.c
        EjerciciosClase/EjemploSigterm/ejemplosSigterm_ignore.c
        EjerciciosClase/Ejercicio0/ejercicio0.c
        EjerciciosClase/Ejercicio1/ejercicioClase.c
        EjerciciosClase/Ejercicio2/ejercicioClase2.c
        EjerciciosClase/Ejercicio2.3/ejercicio23.c
        EjerciciosClase/Ejercicio2Proc1Arch/ejercicioprocesosarchivo.c
        EjerciciosClase/Ejercicio3/ejercicioClase3.c
        EjerciciosClase/Ejercicio3.1/ejercicio31.c
        EjerciciosClase/Ejercicio3.3/ejercicio33.c
        EjerciciosClase/Ejercicio3.4/ejercicio34.c
        EjerciciosClase/Ejercicio4/ejercicio4.c
        EjerciciosClase/Ejercicio4.1/ejercicio41.c
        EjerciciosClase/Ejercicio5/ejercicio5.c
        EjerciciosClase/EjercicioFork/fork.c
        EjerciciosClase/EjercicioHilos/ejercicioHilos.c
        EjerciciosClase/EjercicioTema2/ejercicioclase.c
        EjerciciosClase/ErrorLLamadasSist/errorCall.c
        EjerciciosClase/HolaAdiosSem/ejercicioclase.c
        EjerciciosClase/Semaforos/semaforo.c
        EjerciciosClase/Tema5/ejercicioBanco.c
        Practica1/Ejercicio2/Ejercicio2.c
        Practica1/Ejercicio3/Ejercicio3.c
        Practica1/Ejercicio4/Ejercicio4.c
        Practica2/Ejercicio1/ejercicio1.c
        Practica2/Ejercicio2/ejercicio2.c
        PrimerProgra/Ejercicio3/ejercicio3.c
        PrimerProgra/miprimerprograma.c EjerciciosClase/Ejercicio4Abril/abril4.cpp EjerciciosClase/Ejercicio4Abril/abril4.h)
