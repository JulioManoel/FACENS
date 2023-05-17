import mongoose, { Schema } from "mongoose";

const User = new Schema({
    name: { type: String, required: true },
    age: { type: Number, required: true }
})
export default mongoose.model('User', User)