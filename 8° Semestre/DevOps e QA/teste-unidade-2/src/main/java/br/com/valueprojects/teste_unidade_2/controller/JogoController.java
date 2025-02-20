package br.com.valueprojects.teste_unidade_2.controller;

import org.springframework.web.bind.annotation.*;

import br.com.valueprojects.teste_unidade_2.model.Jogo;
import br.com.valueprojects.teste_unidade_2.model.Juiz;

import java.util.ArrayList;
import java.util.List;

@RestController

@RequestMapping("/jogos")
public class JogoController {

    private List<Jogo> jogos = new ArrayList<>();
    private Juiz juiz = new Juiz();

    // Criar um novo jogo
    @PostMapping("/criar")
    public Jogo criarJogo(@RequestBody String descricao) {
        Jogo jogo = new Jogo(descricao);
        jogos.add(jogo);
        return jogo;
    }

   
    // Julgar um jogo
    @PostMapping("/{id}/julgar")
    public String julgarJogo(@PathVariable int id) {
        Jogo jogo = jogos.get(id);
        juiz.julga(jogo);
        double primeiroColocado = juiz.getPrimeiroColocado();
        double ultimoColocado = juiz.getUltimoColocado();
        return "Primeiro colocado: " + primeiroColocado + ", Último colocado: " + ultimoColocado;
    }

    // Listar todos os jogos
    @GetMapping
    public List<Jogo> listarJogos() {
        return jogos;
    }

}

