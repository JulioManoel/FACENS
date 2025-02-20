package com.example.demo.model;

public class Curso {
	private String nome;
	private Double nota;
	
	public Curso(String nome) {
        this.nome = nome;
    }
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}	
	
	public Double getNota() {
		return this.nota;
	}
	
	public void setNota(Double nota) {
		this.nota = nota;
	}
}
