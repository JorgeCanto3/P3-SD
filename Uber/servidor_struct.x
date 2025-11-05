struct Uber{
    string placas;
    bool disponible;
    int posicion [2];
    int Tarifa;
    string Tipo;
}

int const Vehiculos = 8;

program UBER_SERV {
    version UBER_SERV {
        Uber obtener_uber(string placas) = 1;
        bool actualizar_disponibilidad(string placas, bool disponible) = 2;
        int calcular_tarifa(string tipo, int distancia) = 3;
    } = 1;
} = 0x20000003;