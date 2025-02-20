package com.example.demo.model;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Aluno {
	private String nome;
	private String email;
	private String senha;
	private List<Curso> cursosAtribuidos = new ArrayList<>();
	private List<Curso> cursosConcluidos = new ArrayList<>();
	
	public Aluno(String nome, Curso curso) {
		this.nome = nome;
		this.cursosAtribuidos.add(curso);
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getEmail() {
		return this.email;
	}
	
	public void setEmail(String email) {
		this.email = email;
	}
	
	public String getSenha() {
		return this.senha;
	}
	
	public List<Curso> getCursosAtribuidos() {
		return this.cursosAtribuidos;
	}
	
	public void setCursosAtribuidos(List<Curso> cursos) {
		this.cursosAtribuidos = cursos;
	}
	
	public List<Curso> getCursosConcluidos() {
		return this.cursosConcluidos;
	}
	
	public void setCursosConcluidos(List<Curso> cursos) {
		this.cursosConcluidos = cursos;
	}
	
	public boolean removerCursoAtribuido(Curso curso) {
        return cursosAtribuidos.remove(curso);
    }
	
	public void concluirCurso(String nomeCurso, Double nota, List<Curso> cursos) {
		Curso curso = this.cursosAtribuidos.stream()
			.filter(c -> c.getNome().equalsIgnoreCase(nomeCurso))
            .findFirst()
            .orElse(null);
		if (curso == null) throw new IllegalArgumentException("Curso não encontrado: " + nomeCurso);

		this.removerCursoAtribuido(curso);
		curso.setNota(nota);
		this.cursosConcluidos.add(curso);
		
		if (nota >= 6.9) return;
		
		Random random = new Random();
		for (int i = 0; i < 3 && !cursos.isEmpty(); i++) {
            Curso cursoAleatorio = cursos.remove(random.nextInt(cursos.size()));
            cursosAtribuidos.add(cursoAleatorio);
        }
	}
}
