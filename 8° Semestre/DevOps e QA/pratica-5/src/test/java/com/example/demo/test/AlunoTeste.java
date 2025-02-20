package com.example.demo.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;

import java.util.List;

import com.example.demo.model.*;

public class AlunoTeste {	
	@Test
	public void deveTestarAlunoGanhouCursos() {
		List<Curso> cursosDisponiveis = List.of(
			new Curso("Matemática"),
			new Curso("Programação"),
            new Curso("História"),
            new Curso("Portugues"),
            new Curso("Ingles"),
            new Curso("QA")
        );
		
		Curso cursoInicial = new Curso("Ciencias");
		Aluno aluno = new Aluno("João", cursoInicial);
		
		aluno.concluirCurso("Ciencias", 7.0, cursosDisponiveis);
		
		List<Curso> cursosAtribuidos = aluno.getCursosAtribuidos();
		assertEquals(3, cursosAtribuidos.size());
	}
	
	@Test
	public void deveTestarAlunoNaoGanhouCursos() {
		List<Curso> cursosDisponiveis = List.of(
			new Curso("Matemática"),
			new Curso("Programação"),
            new Curso("História"),
            new Curso("Portugues"),
            new Curso("Ingles"),
            new Curso("QA")
        );
		
		Curso cursoInicial = new Curso("Ciencias");
		Aluno aluno = new Aluno("João", cursoInicial);
		
		aluno.concluirCurso("Ciencias", 6.9, cursosDisponiveis);
		
		List<Curso> cursosAtribuidos = aluno.getCursosAtribuidos();
		assertEquals(3, cursosAtribuidos.size());
	}
	
	@Test
	public void deveTestarErroAoEncontrarCurso() {
		List<Curso> cursosDisponiveis = List.of(
			new Curso("Matemática"),
			new Curso("Programação"),
            new Curso("História"),
            new Curso("Portugues"),
            new Curso("Ingles"),
            new Curso("QA")
        );
		
		Curso cursoInicial = new Curso("Ciencias");
		Aluno aluno = new Aluno("João", cursoInicial);

		assertThrows(IllegalArgumentException.class, () -> {
            aluno.concluirCurso("Biologia", 7.0, cursosDisponiveis);
        });
	}
}
