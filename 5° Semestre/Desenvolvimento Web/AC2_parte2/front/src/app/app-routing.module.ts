import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ListagemComponent } from './components/listagem/listagem.component';
import { ExibicaoComponent } from './components/exibicao/exibicao.component';
import { EdicaoComponent } from './components/edicao/edicao.component';
import { CadastroComponent } from './components/cadastro/cadastro.component';

const routes: Routes = [
  // { path: '/', redirectTo: 'listagem', pathMatch: 'full' },
  { path: 'listagem', component: ListagemComponent },
  { path: 'cadastro', component: CadastroComponent },
  { path: 'exibicao/:id', component: ExibicaoComponent },
  { path: 'edicao/:id', component: EdicaoComponent },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
