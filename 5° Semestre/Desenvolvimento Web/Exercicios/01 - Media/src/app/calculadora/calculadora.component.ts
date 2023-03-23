import { Component } from '@angular/core';

@Component({
  selector: 'app-calculadora',
  templateUrl: './calculadora.component.html',
  styleUrls: ['./calculadora.component.css']
})
export class CalculadoraComponent {
  res?: number;
  num1: number = 0;
  num2: number = 0;
  operacao?:string;

  calcula() {
    if(this.operacao == 'multi') {
      this.res = this.num1 * this.num2;
    }
    else if(this.operacao == 'div') {
      this.res = this.num1 / this.num2;
    }
    else if(this.operacao == 'soma') {
      this.res = this.num1 + this.num2;
    }
    else if(this.operacao == 'sub') {
      this.res = this.num1 - this.num2;
    }
  }

  calculaFilled(): boolean {
    return typeof this.res === 'number';
  }
}
