package negocio.oficina;

import utilities.Utils;

public class TOficina {
	
	private int id;
	private String nombre;
	private boolean activo;

	public TOficina(String nombre) {
		this.nombre = nombre;
		this.activo = true;
	}

	public TOficina(int id, String nombre, boolean activo) {
		this.id = id;
		this.nombre = nombre;
		this.activo = activo;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public boolean isActivo() {
		return activo;
	}

	public void setActivo(boolean activo) {
		this.activo = activo;
	}

	@Override
	public String toString() {
		return "ID: " + this.id + Utils.SALTO +
				"Nombre: " + this.nombre + Utils.SALTO +
				"Activo: " + (this.activo ? "si" : "no") + Utils.SALTO;		
	}
}