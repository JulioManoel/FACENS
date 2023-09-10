import { Component } from '@angular/core';
import { FormControl, FormGroup } from '@angular/forms';
import { Router } from '@angular/router';
import { IPokemon, Pokemon } from 'src/app/interfaces/pokemon';
import { JogadorService } from 'src/app/services/jogador.service';
import { PokemonService } from 'src/app/services/pokemon.service';

@Component({
  selector: 'app-cadastro',
  templateUrl: './cadastro.component.html',
  styleUrls: ['./cadastro.component.css']
})
export class CadastroComponent {
  form: FormGroup = new FormGroup({
    nome: new FormControl(''),
    pokemon: new FormControl('')
  })
  pokemons?: Pokemon[]

  constructor(
    private pokemonService:PokemonService,
    private jogadorService:JogadorService,
    private router:Router
    ){}

  ngOnInit(): void {
    this.getPokemon();
  }

  getPokemon() {
    this.pokemonService.getListPokemon().subscribe({
      next: response => {
        this.pokemons = response.results
        console.log(this.pokemons)
      },
      error: erro => {
        console.error(erro)
      }
    })
  }

  cadastrar() {
    this.jogadorService.cadastrarJogador(this.form.value.name, this.form.value.pokemon).subscribe({
      next: response => {
        this.router.navigate(['listagem'])
      },
      error: erro => {
        console.error(erro)
      }
    })
  }
}
