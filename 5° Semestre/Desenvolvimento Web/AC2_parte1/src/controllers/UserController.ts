import { Request, Response } from "express";
import User from "../models/user"

class UserController {
    async list(request: Request, response: Response) {
        const data = await User.find()
        response.status(200).json(data)
    }
    async create(request: Request, response: Response) {
        const {name} = request.body
        try {
            const user = await User.create({name})
            response.status(200).json(user)
        } catch (error) {
            response.status(500).json({error:'Erro ao criar usuário', message: error})
        }
    }
    async delete(request: Request, response: Response) {
        try {
            const count = await User.count()
            if(count == 0) {
                response.status(409).json({ error: 'Lista Vazia' })
                return
            }
            const index = Math.floor(Math.random() * count)
            const users = await User.find()
            const user = await User.deleteOne({name: users[index].name})
            response.status(200).json(user)
            //response.status(200).json({message: count})
        } catch (error) {
            response.status(500).json({ error: 'Erro ao apagar usuário', message: error})
        }
    }
}

export default new UserController()