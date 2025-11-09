dconst Vehiculos = 8;

enum TipoUber {
    UberPlanet = 0,
    UberXL = 1,
    UberBlack = 2
};

struct Posicion {
    int x;
    int y;
};

struct Uber {
    char placas[10];
    bool disponible;
    Posicion posicion;
    int tarifa;
    TipoUber tipo;
};

struct Servicio {
    int viajesRealizados;
    int numAutos;
    int ganancia;
};

struct TerminarViajeArgs{
    Posicion final;
    int costoViaje;
    char placas[10];
};

program uber_prog {
    version uber_ver {
        Uber solicitarViaje(Posicion pasajero) = 1;
        void TerminarViaje(TerminarViajeArgs args) = 2;
        Servicio estadoServicio() = 3;
    } = 1;
} = 0x20000003;
