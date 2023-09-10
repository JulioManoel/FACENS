import { Request, Response } from 'express'
import Jogador from '../models/Jogador'


class JogadorController {

  async listAll(request: Request, response: Response) {
    const jogador = await Jogador.find()
    response.json(jogador)
  }

  async create(request: Request, response: Response) {
    const { name, pokemon } = request.body;
    const jogador = await Jogador.create({ name: name, pokemon: pokemon })
    response.status(201).json(jogador)
  }

  async get(request: Request, response: Response) {
    const { id } = request.params;

    if (id.length != 24) {
      return response.status(422).json({
        message: `Usuário não encontrado`
      })
    }

    const jogador = await Jogador.findById(id);
    if (jogador)
      return response.status(201).json(jogador);
    return response.status(404).json({
      message: `Herói ${id} não encontrado`
    })
  }

  async update(request: Request, response: Response) {
    const { id } = request.params;
    const { name, pokemon } = request.body;
    Jogador.findByIdAndUpdate(id, {name: name, pokemon: pokemon}, {new: true})
      .then((jogador) => {
        if (jogador) 
          return response.status(201).json(jogador);
        return response.status(404).json({ message: `Usuário ${id} não encontrado!` });
      });
  }

}

export default new JogadorController();