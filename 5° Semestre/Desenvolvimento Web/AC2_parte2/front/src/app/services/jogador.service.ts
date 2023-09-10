import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { IJogador } from '../interfaces/jogador';

@Injectable({
  providedIn: 'root'
})
export class JogadorService {

  constructor(private http:HttpClient) { }

  getListJogador(): Observable<IJogador[]>{
    return this.http.get<IJogador[]>(`http://localhost:3000/api/jogador`)
  }

  cadastrarJogador(name: String, pokemon: String): Observable<void> {
    return this.http.post<void>(`localhost:3000/api/jogador`, {name: name, pokemon: pokemon})
  }


}
