import { Component } from '@angular/core';

@Component({
  selector: 'app-media',
  templateUrl: './media.component.html',
  styleUrls: ['./media.component.css']
})
export class MediaComponent {
  aprovado?: string;
  media?: number;
  ac1: number = 0;
  ac2: number = 0;
  ag: number = 0;
  af: number = 0;

  calcularMedia() {
    this.media = (this.ac1 * 0.15) + (this.ac2 * 0.3) + (this.ag * 0.1) + (this.af * 0.45);
    
    if(this.media >= 5)
      this.aprovado = "Aprovado"
    else
      this.aprovado = "Reprovado"
  }

  mediaFilled(): boolean {
    return typeof this.media === "number";
  }
}
