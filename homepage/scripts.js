document.addEventListener('DOMContentLoaded', function(){

    let upbutton1 = document.querySelector("#upbutton1");
    let upbutton2 = document.querySelector("#upbutton2");
    let upbutton3 = document.querySelector("#upbutton3");
    let upbutton4 = document.querySelector("#upbutton4");
    let upbutton5 = document.querySelector("#upbutton5");

    let downbutton1 = document.querySelector("#downbutton1");
    let downbutton2 = document.querySelector("#downbutton2");
    let downbutton3 = document.querySelector("#downbutton3");
    let downbutton4 = document.querySelector("#downbutton4");
    let downbutton5 = document.querySelector("#downbutton5");


    upbutton1.addEventListener('click', function(){
        let agi = document.querySelector("#agi").value;
        agi = parseInt(agi);
        if (agi <= 2){
            document.querySelector("#agi").value = agi + 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare -1;
        }
        else {
            window.alert("Initial attribute limit is 3");
        }


    })

    upbutton2.addEventListener('click', function(){
        let int = document.querySelector("#int").value;
        int = parseInt(int);
        if (int <= 2){
            document.querySelector("#int").value = int + 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare -1;
        }
        else{
            window.alert("Initial attribute limit is 3");
        }
    })

    upbutton3.addEventListener('click', function(){
        let vig = document.querySelector("#vig").value;
        vig = parseInt(vig);
        if (vig <= 2){
            document.querySelector("#vig").value = vig + 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare -1;
        }
        else{
            window.alert("Initial attribute limit is 3");
        }

    })

    upbutton4.addEventListener('click', function(){
        let pre = document.querySelector("#pre").value;
        pre = parseInt(pre);
        if (pre <= 2){
            document.querySelector("#pre").value = pre + 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare -1;
        }
        else{
            window.alert("Initial attribute limit is 3");
        }
    })

    upbutton5.addEventListener('click', function(){
        let str = document.querySelector("#str").value;
        str = parseInt(str);
        if (str <= 2){
            document.querySelector("#str").value = str + 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare -1;
        }
        else{
            window.alert("Initial attribute limit is 3");
        }
    })

    downbutton1.addEventListener('click', function(){
        let agi = document.querySelector("#agi").value;
        agi = parseInt(agi);
        if (agi > 0){
            document.querySelector("#agi").value = agi - 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare +1;
        }
        else{
            window.alert("Initial attribute limit is 0");
        }
    })

    downbutton2.addEventListener('click', function(){
        let int = document.querySelector("#int").value;
        int = parseInt(int);
        if (int > 0){
            document.querySelector("#int").value = int - 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare +1;
        }
        else{
            window.alert("Initial attribute limit is 0");
        }
    })

    downbutton3.addEventListener('click', function(){
        let vig = document.querySelector("#vig").value;
        vig = parseInt(vig);
        if (vig > 0){
            document.querySelector("#vig").value = vig - 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare +1;
        }
        else{
            window.alert("Initial attribute limit is 0");
        }
    })

    downbutton4.addEventListener('click', function(){
        let pre = document.querySelector("#pre").value;
        pre = parseInt(pre);
        if (pre > 0){
            document.querySelector("#pre").value = pre - 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare +1;
        }
        else{
            window.alert("Initial attribute limit is 0");
        }
    })

    downbutton5.addEventListener('click', function(){
        let str = document.querySelector("#str").value;
        str = parseInt(str);
        if (str > 0){
            document.querySelector("#str").value = str - 1;
            let spare = document.querySelector("#spare").value
            spare = parseInt(spare);
            document.querySelector("#spare").value = spare +1;
        }
        else{
            window.alert("Initial attribute limit is 0");
        }
    })
})