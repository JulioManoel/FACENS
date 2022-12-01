using System.Collections;
using System.Collections.Generic;
using UnityEngine;
 using UnityEngine.UI;
public class ScoreManager : MonoBehaviour
{
    public Text pontos;   
    public Text record;
    int scoreMax = 0;
    int points = 0 ;
    // Start is called before the first frame update
    void Start()
    {
        pontos.text = "0";
        record.text = PlayerPrefs.GetInt("point").ToString();
        scoreMax = PlayerPrefs.GetInt("point");             
    }

    public void UpdateScore( int score)
    {
        points += score;
        if(scoreMax < points)
        {
            scoreMax = points;
            record.text = scoreMax.ToString ();
            PlayerPrefs.SetInt("point",scoreMax);                
            PlayerPrefs.Save();
   
        }        
        pontos.text = points.ToString ();
    }

    public void GameOver()
    {
        pontos.text = "0";
        points = 0;
    }
}
