import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { CarroExibicaoComponent } from './carro-exibicao/carro-exibicao.component';
import { HomeComponent } from './home/home.component';


const routes: Routes = [
  {path: 'carro/:id', component: CarroExibicaoComponent},
  {path: 'home', component: HomeComponent},
  {path: '', redirectTo: '/home', pathMatch: 'full'}  
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
