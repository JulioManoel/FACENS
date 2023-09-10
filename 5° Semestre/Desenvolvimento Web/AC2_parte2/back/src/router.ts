import { Router, Request, Response } from 'express'
import JogadorController from './controllers/JogadorController'

export const router = Router()

router.get('/api/jogador', JogadorController.listAll)
router.get('/api/jogador/:id', JogadorController.get)
router.post('/api/jogador', JogadorController.create)
router.put('/api/jogador/:id', JogadorController.update)