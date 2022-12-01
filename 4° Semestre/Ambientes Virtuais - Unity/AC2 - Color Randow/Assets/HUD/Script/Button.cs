using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;


public class Button : MonoBehaviour, IPointerDownHandler, IPointerUpHandler {

 public int input;
 bool pressing;

 public void OnPointerDown(PointerEventData eventData){
 pressing = true;
 }

 public void OnPointerUp(PointerEventData eventData){
 pressing = false;
 }

    // Update is called once per frame
    void Update()
    {
        if(pressing){
            input = 1;
        }

        else{
            input = 0;
        }

        input = Mathf.Clamp (input, 0,1);
    }
}
