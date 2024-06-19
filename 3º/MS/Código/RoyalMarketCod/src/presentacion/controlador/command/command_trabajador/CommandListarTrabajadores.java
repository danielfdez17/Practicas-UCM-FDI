package presentacion.controlador.command.command_trabajador;

import java.util.List;

import negocio.factoriaNegocio.FactoriaNegocio;
import negocio.trabajador.TTrabajador;
import presentacion.controlador.command.Command;
import presentacion.controlador.Eventos;
import presentacion.factoriaVistas.Context;

public class CommandListarTrabajadores implements Command {
	public Context execute(Object datos) {
		List<TTrabajador> trabajadores = FactoriaNegocio.getInstancia().crearSATrabajador().listarTrabajadores();
		if(trabajadores == null || trabajadores.isEmpty()) return new Context(Eventos.LISTAR_TRABAJADORES_KO, trabajadores);
		return new Context(Eventos.LISTAR_TRABAJADORES_OK, trabajadores);
	}
	@Override
	public Eventos getId() {
		return Eventos.LISTAR_TRABAJADORES;
	}
}