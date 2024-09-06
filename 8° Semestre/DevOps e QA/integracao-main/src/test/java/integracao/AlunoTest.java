package integracao;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class AlunoTest {
	Aluno aluno;

	@Test
	public void testCalcularAprovacao_ReprovacaoFrequencia(){
		aluno = new Aluno();
		aluno.setFrequencia(74);
		assertEquals(false, aluno.calcularAprovacao());
	}

	@Test
	public void testCalcularAprovacao_ReprovacaoNota() {
		aluno = new Aluno();
		aluno.setFrequencia(75);
		aluno.setNota1 (29);
		aluno.setNota2 (30);
		assertEquals(false, aluno.calcularAprovacao());
	}

	@Test
	public void testAprovacao_AprovacaoNota(){
		aluno = new Aluno();
		aluno.setFrequencia(75);
		aluno.setNota1 (70);
		aluno.setNota2 (70);
		assertEquals(true, aluno.calcularAprovacao());
	}

	@Test
	public void testAprovacao_AprovacaoFinal(){
		aluno = new Aluno();
		aluno.setFrequencia(75);
		aluno.setNota1 (30);
		aluno.setNota2 (30);
		aluno.setNotaFinal (70);
		assertEquals(true, aluno.calcularAprovacao());
	}

	@Test
	public void testCalcularAprovacao_ReprovacaoFinal(){
		aluno = new Aluno();
		aluno.setFrequencia(75);
		aluno.setNota1 (30);
		aluno.setNota2 (30);
		aluno.setNotaFinal (69);
		assertEquals(false, aluno.calcularAprovacao());
	}
	
	@Test
	public void testCalcularAprovacao_AprovacaoLimiteFrequencia() {
		aluno = new Aluno();
		aluno.setFrequencia(75);
		aluno.setNota1(70);
		aluno.setNota2(70);
		assertEquals(true, aluno.calcularAprovacao());
	}
	
	@Test
	public void testCalcularAprovacao_ReprovacaoLimiteFrequencia() {
		aluno = new Aluno();
		aluno.setFrequencia(74);
		aluno.setNota1(70);
		aluno.setNota2(70);
		assertEquals(false, aluno.calcularAprovacao());
	}
	
	@Test
	public void testGetFrequencia() {
		aluno = new Aluno();
		aluno.setFrequencia(75);
		assertEquals(75, aluno.getFrequencia());
	}
	
	@Test
	public void testGetNota1() {
		aluno = new Aluno();
		aluno.setNota1(75);
		assertEquals(75, aluno.getNota1(), 0.001);
	}
	
	@Test
	public void testGetNota2() {
		aluno = new Aluno();
		aluno.setNota2(70);
		assertEquals(70, aluno.getNota2(), 0.001);
	}
}
