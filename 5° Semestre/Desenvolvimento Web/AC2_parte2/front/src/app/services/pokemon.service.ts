import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { IPokemon } from '../interfaces/pokemon';

@Injectable({
  providedIn: 'root'
})
export class PokemonService {

  constructor(private http: HttpClient) { }

  getListPokemon(): Observable<IPokemon>{
    return this.http.get<IPokemon>(`https://pokeapi.co/api/v2/pokemon/?offset=0&limit=1281`)
  }
}
