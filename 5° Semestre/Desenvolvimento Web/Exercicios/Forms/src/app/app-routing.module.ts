import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ReactiveFormsComponent } from './components/reactive-forms/reactive-forms.component';
import { TemplatDrivenComponent } from './components/templat-driven/templat-driven.component';

const routes: Routes = [
  {path: 'TemplateDriven', component: TemplatDrivenComponent},
  {path: 'ReactiveForms', component: ReactiveFormsComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
