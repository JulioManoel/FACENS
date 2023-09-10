import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { IJogador } from 'src/app/interfaces/jogador';
import { JogadorService } from 'src/app/services/jogador.service';

@Component({
  selector: 'app-listagem',
  templateUrl: './listagem.component.html',
  styleUrls: ['./listagem.component.css']
})
export class ListagemComponent {
  jogadores?: IJogador[]

  constructor(
    private jogadorService: JogadorService,
    private router: Router
    ) {}

  ngOnInit(): void {
    this.getJogadores();
  }

  getJogadores() {
    this.jogadorService.getListJogador().subscribe({
      next: response => {
        this.jogadores = response
      },
      error: erro => {
        console.error(erro)
      }
    })
  }

  exibicao(_id: String) {
    this.router.navigate(['exibicao', _id])
  }

  edicao(_id: String) {
    this.router.navigate(['edicao', _id])
  }
}
