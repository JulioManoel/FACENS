import { Component } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { Carro } from '../Carro';
import { carros } from '../carros'

@Component({
  selector: 'app-carro-exibicao',
  templateUrl: './carro-exibicao.component.html',
  styleUrls: ['./carro-exibicao.component.css']
})
export class CarroExibicaoComponent {
  carro: Carro = new Carro(0, '', 0, 0)
  carros: Carro[] = carros;
  id?: number

  constructor(private route: ActivatedRoute, private router: Router){}

  ngOnInit() {
    this.id = +this.route.snapshot.params['id'] ?? 0
    carros.forEach(element => {
      if(element.id === this.id) {
        this.carro = element
      }
    });
  }

  voltar() {
    this.router.navigate(['/home'])
  }
}
