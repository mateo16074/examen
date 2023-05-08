#include <stdio.h>
#include <string.h>
// variables globales para almacenar una usuario y contraseña 
char usuario1[20] = "Mati";
char usuario2[20] = "alan";
char usuario3[20] = "isacc";
// Contraseñas preestablecidas
int contrasena1 = 1234;
int contrasena2 = 456;
int contrasena3 = 789;

//se usa la funcion strcmp para poder comparar los caracteres de usuario y contraseña que ingrese en usuario, si es corecto nos devuelve un 1 como true o un 0 como false 
int login(char nombre_usuario[20], int clave) {
    if(strcmp(nombre_usuario, usuario1) == 0 && clave == contrasena1) {
        return 1;
    } else if(strcmp(nombre_usuario, usuario2) == 0 && clave == contrasena2) {
        return 1;
    } else if(strcmp(nombre_usuario, usuario3) == 0 && clave == contrasena3) {
        return 1;
    } else {
        return 0;
    }
}
float calcularPrecioRuta(char tipoRuta, float distancia) {
    float precioPorKm;
    if (tipoRuta == 'urbana') {
        precioPorKm = 0.10;
    } else if (tipoRuta == 'interurbana') {
        precioPorKm = 0.15;
    } else {
        precioPorKm = 0.20;
    }
    return precioPorKm * distancia;
}

float calcularDescuento(float costoTotal) {
    float descuento = 0.0;
    if (costoTotal >= 500.0) {
        descuento = 0.20 * costoTotal;
    } else if (costoTotal >= 100.0) {
        descuento = 0.10 * costoTotal;
    } else if (costoTotal >= 50.0) {
        descuento = 0.05 * costoTotal;
    }
    return descuento;
}
void operacionTransporte() {
printf("\ operaciónTransporte\n");
for (int i = 1; i <= 5; i++) {
    printf("\nCliente %d\n", i);
    char tipoRuta;
    float distancia;
    printf("Ingrese el tipo de ruta urbana, interurbana, internacional: ");
    scanf(" %c", &tipoRuta);
    printf("Ingrese la distancia en kilómetros: ");
    scanf("%f", &distancia);
    float precio = calcularPrecioRuta(tipoRuta, distancia);
    float descuento = calcularDescuento(precio);
    float total = precio - descuento;
    printf("Subtotal: $%.2f\n", precio);
    printf("Descuento: $%.2f\n", descuento);
    printf("Total: $%.2f\n", total);
    }
}
int menu() {
    int opcion = 0;
    
    do {
        // Mostrar opciones del menú
        printf("1.Operacion_de_transporte\n");
        printf("2. red_social\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        
        // Leer la opción seleccionada
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("Seleccionó Operacion_de_transporte\n");
                operacionTransporte();
                break;
            case 2:
                printf("Seleccionó red_social\n");
                // Agregar aquí el código para la opción 2
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            
        }
        
        printf("\n"); 
    } while(opcion != 3);
    
    return 0;
}

int main() {
    char nombre_usuario[20];
    int clave;
    int intentos = 0;
    int ingreso_valido = 0;
    
    do {
        printf("Ingrese el nombre de usuario: ");
        scanf("%s", nombre_usuario);
        printf("Ingrese la clave: ");
        scanf("%d", &clave);
        
        ingreso_valido = login(nombre_usuario, clave);
        
        if(!ingreso_valido) {
            intentos++;
            printf("Usuario o clave incorrectos. Intento #%d\n", intentos);
        }
        
    } while(intentos < 3 && !ingreso_valido);
    
    if(ingreso_valido) {
        printf("Ingreso exitoso!\n");
        menu();
    } else {
        printf("Imposible ingresar. Intentos máximos alcanzados.\n");
    }
    
    return 0;
}

  
