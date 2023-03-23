import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { Carro } from '../Carro';
import { carros } from '../carros'

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent {
  carros: Carro[] = carros;
  id: number = 0

  constructor(private route: ActivatedRoute){}

  ngOnInit() {
    this.id = +this.route.snapshot.params['id'] ?? 0
  }
}
