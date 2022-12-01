public class Ponto {
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public Ponto(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public double caculaDistancia(Ponto p){
        int difX = this.x - p.getX();
        int difY = this.y - p.getY();
        return Math.sqrt(Math.pow(difX,2)+Math.pow(difY,2));
    }

}
