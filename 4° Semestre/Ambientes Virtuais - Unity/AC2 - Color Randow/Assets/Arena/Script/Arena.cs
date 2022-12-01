using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[System.Serializable]
public class Arena
{    
    public Color colorChao;
    public GameObject[] arena;
    public Image panel;
    public Color[]  color = { 
        Color.black, Color.blue, Color.cyan, Color.gray, Color.green, 
        Color.grey, Color.magenta, Color.red, Color.white, Color.yellow
    };

    public void selectColor()
    {
        GameObject chao = arena[Random.Range(0, arena.Length-1)];
        colorChao = chao.GetComponent<Renderer>().material.color;
        //GameObject panel = GameObject.FindWithTag("colorBack");
        panel.color = colorChao;
    }

    public void setColorArena()
    {
        arena  = GameObject.FindGameObjectsWithTag("Arena");
        foreach (var chao in arena) {
            int index  = Random.Range(0, 9);
            chao.GetComponent<Renderer>().material.color = color[index];
        }
    }

    public void dropArena()
    {
        foreach (var chao in arena) {
            Color groundColor = chao.GetComponent<Renderer>().material.color;
            if(groundColor != colorChao) {
                chao.GetComponent<Renderer>().enabled = false;
                chao.GetComponent<Collider>().enabled = false;
            }
        }
    }

    public void restArena()
    {
        foreach (var chao in arena) {
            Color groundColor = chao.GetComponent<Renderer>().material.color;
            if(groundColor != colorChao) {
                chao.GetComponent<Renderer>().enabled = true;
                chao.GetComponent<Collider>().enabled = true;
            }
        }
    }
    
    public void hidden()
    {
        GameObject gameOver = GameObject.FindWithTag("gameOver");
        gameOver.GetComponent<Renderer>().enabled = false;
    }
}
