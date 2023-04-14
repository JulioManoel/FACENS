import { Component, ViewChild } from '@angular/core';
import { NgModel } from '@angular/forms';

@Component({
  selector: 'app-templat-driven',
  templateUrl: './templat-driven.component.html',
  styleUrls: ['./templat-driven.component.css']
})
export class TemplatDrivenComponent {
  @ViewChild('form')form!: NgModel
  name?: string
  email?: string
  password?: string
  confirma?: string

  onSubmit(){
    console.log(this.form)
  }
}
