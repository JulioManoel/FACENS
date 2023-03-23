import { Component } from '@angular/core';

@Component({
  selector: 'app-cadastro-aluno',
  templateUrl: './cadastro-aluno.component.html',
  styleUrls: ['./cadastro-aluno.component.css']
})
export class CadastroAlunoComponent {
  registroAluno: number = 0
  nome: string = ''
  email: string = ''
  celular: number = 0
  enviado: boolean = false

  submit() {

  }



}
