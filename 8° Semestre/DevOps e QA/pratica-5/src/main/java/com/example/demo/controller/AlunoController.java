package com.example.demo.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

import com.example.demo.model.*;

@RequestMapping("/aluno")
public class AlunoController {
	private List<Aluno> alunos = new ArrayList<Aluno>();
	
	@PostMapping("/criar")
    public Aluno store(@RequestBody String nomeCurso, @RequestBody String nome) {
		Curso curso = new Curso(nomeCurso);
        Aluno aluno = new Aluno(nome, curso);
        alunos.add(aluno);
        return aluno;
    }
	
	@PostMapping("/{id}/concluir")
    public String julgarJogo(@PathVariable int id, @RequestBody String nomeCurso, @RequestBody Double nota, @RequestBody List<Curso> cursos) {
        Aluno aluno = alunos.get(id);
        aluno.concluirCurso(nomeCurso, nota, cursos);
        return "Cursos Disponiveis: " + aluno.getCursosAtribuidos();
    }
	
	@GetMapping
    public List<Aluno> listarAluno(@RequestBody String descricao) {
        return alunos;
    }
}