package poo.vehiculo;

import java.util.ArrayList;

class Pieza {
    private String nombre;
    private double precio;

    public Pieza(String nombre, double precio) {
        this.nombre = nombre;
        this.precio = precio;
    }

    public String getNombre() {
        return nombre;
    }

    public double getPrecio() {
        return precio;
    }
}

class Vehiculo {
    private String matricula;
    private String marca;
    private String modelo;
    private ArrayList<Pieza> piezas;

    public Vehiculo(String matricula, String marca, String modelo) {
        this.matricula = matricula;
        this.marca = marca;
        this.modelo = modelo;
        this.piezas = new ArrayList<>();
    }

    public void agregarPieza(Pieza pieza) {
        piezas.add(pieza);
    }

    public ArrayList<Pieza> getPiezas() {
        return piezas;
    }
}

class Taller {
    private String nombre;
    private String telefono;
    private double precioHora;

    public Taller(String nombre, String telefono, double precioHora) {
        this.nombre = nombre;
        this.telefono = telefono;
        this.precioHora = precioHora;
    }

    public double repararVehiculo(Vehiculo vehiculo, int horas) {
        double costoPiezas = 0;
        for (Pieza pieza : vehiculo.getPiezas()) {
            costoPiezas += pieza.getPrecio();
        }
        double costoHora = horas * precioHora;
        return costoPiezas + costoHora;
    }
}

public class PruebaTaller {
    public static void main(String[] args) {
        // Crear algunas piezas
        Pieza pieza1 = new Pieza("Freno", 100);
        Pieza pieza2 = new Pieza("Aceite", 50);

        // Crear un vehículo y agregarle piezas
        Vehiculo vehiculo = new Vehiculo("123ABC", "Toyota", "Corolla");
        vehiculo.agregarPieza(pieza1);
        vehiculo.agregarPieza(pieza2);

        // Crear un taller
        Taller taller = new Taller("Taller A", "123456789", 50);

        // Calcular el costo de la reparación
        double costoReparacion = taller.repararVehiculo(vehiculo, 3);
        System.out.println("El costo de la reparación es: $" + costoReparacion);
    }
}
