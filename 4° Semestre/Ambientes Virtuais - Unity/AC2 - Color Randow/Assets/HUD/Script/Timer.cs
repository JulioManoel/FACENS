using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public Arena arena;
    public GameObject personagem;
    public Text timeLevel_txt;
    private float timeLevel = -10;
    private bool isRestTime = false;
    public ScoreManager score;
    public int point = 1;

    public void triggerStart() {
        arena.hidden();
        restTime();
    }

    // Update is called once per frame
    void Update()
    {
        if(timeLevel >= -3){
            timeLevel -= Time.deltaTime;
        }
        if(timeLevel > 0) {
            timeLevel_txt.text = timeLevel.ToString("F0");
        }
        if(timeLevel < 1 && isRestTime == true) {
            Rigidbody rigidbody = personagem.GetComponent<Rigidbody>();
            rigidbody.useGravity = true;
            arena.dropArena();
        }
        if(timeLevel < -2 && isRestTime == true) {
            isRestTime = false;
            score.UpdateScore(point);
            arena.restArena();
            restTime();
        }
    }

    void restTime(){
        arena.setColorArena();
        arena.selectColor();
        isRestTime = true;
        timeLevel = 10;
    }
}
