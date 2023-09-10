import mongoose from 'mongoose';

const JogadorSchema = new mongoose.Schema({
  name: { type: String, required: true },
  pokemon: { type: String, required: true }
})

export default mongoose.model('Jogador', JogadorSchema);