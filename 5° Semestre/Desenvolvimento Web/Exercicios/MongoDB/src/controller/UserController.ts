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
            response.status(200).json(user);
        } catch(error) {
            response.status(500).json({ error: "Erro ao criar usuário", message: error})
        }
    }

    async update(request: Request, response: Response) {
        const {name, update} = request.body
        try {
            const user = await User.updateOne({ "name": name }, { $set: update})
            console.log(name)
            console.log(update)
            response.status(200).json(user)
        } catch (error) {
            response.status(500).json({ error: "Erro ao apagar usuário", message: error})
        }
    }

    async delete(request: Request, response: Response) {
        const {name} = request.body
        try {
            const user = await User.deleteOne({name})
            response.status(200).json(user)
        } catch (error) {
            response.status(500).json({ error: "Erro ao apagar usuário", message: error})
        }
    }
}
export default new UserController()