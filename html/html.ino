const char MainPage[] PROGMEM = R"=====(
<!DOCTYPE html> 
  <html>
   <head> 
       <title>E-SMART HOME</title> 
       <style> 
          body {
            text-align:center;
            background: lightpink;               
          }
          label{
            position: absolute;
            left: 15px;
            bottom: 5px;
            transition: 0.7s;
          }         
          input {
            height:25px; 
            width:270px;
            font-size:20px;
            margin-bottom: 5px solid #ccc;
            border: 1px solid #b1154a;
            cursor: pointer;
          }
          input[type="password"]::placeholder {
            text-align: right;
          }
          input[type="text"]::placeholder {
             text-align: right;
          }
          #content {
            border: white solid 1px; 
            padding:5px;  
            height:600px; 
            width:400px; 
            border-radius:20px;
            margin: 0 auto
          }
          .ledstatus{
              outline: none;
              margin: 15px 5px;
              width: 50px;
              height: 50px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:white;
              font-size:20px;
              font-weight: bold;
          }
          #ledstatus1{
              border: solid 2px white;
              background: green;
              position: relative;
              left: 200px;
              top: 77px;
          }
          #ledstatus2{
              border: solid 2px white;
              background: green;
              position: relative;
              left: 136px;
              top: 150px;
          }
          #ledstatus3{
              border: solid 2px white;
              background: green;
              position: relative;
              left: 73px;
              top: 225px;
          }
          #ledstatus4{
              border: solid 2px white;
              background: green;
              position: relative;
              left: 8px;
              top: 300px;
          }
          #ledconnect{
            position: relative;
            top: 230px;
            outline: none;
            margin: 0px 5px -1px 5px;
            width: 15px;
            height: 15px;
            border: solid 1px #00EE00;
            background-color: #00EE00;
            border-radius: 50%;
            -moz-border-radius: 50%;
            -webkit-border-radius: 50%;
          }
          .ledconnect_text{
            position: relative;
            top: 230px;
          }
          .button {
            position: relative;           
            right: 70px;
            height:55px; 
            width:200px; 
            margin:10px 0;
            background-color:blueviolet;
            border-radius:10px;
            outline:none;
            color:white;
            font-size:25px;
            font-weight: bold;
          }
          .button_all{
            height:70px; 
            width:140px; 
            margin:10px 0;
            outline:none;
            color:white;
            font-size:20px;
            background-image: linear-gradient(to right, red , blue);
            font-weight: bold;
          }
          #button_on {
            background-color:#00BB00;
            border-radius:10px;
          }
          #button_off {
            background-color:#CC3300;
            border-radius:10px;
          }
          .button_setup {
            height:30px; 
            width:280px; 
            margin:10px 0;
            background-color:blueviolet;
            border-radius:10px;
            outline:none;
            color:white;
            font-size:20px;
            font-weight: bold;
          }
          .button_wifi{
            height:50px; 
            width:90px; 
            margin:10px 0;
            outline:none;
            color:white;
            font-size:15px;
            font-weight: bold;
          }
          #button_save {
            background-color:#00BB00;
            border-radius:5px;
          }
          #button_restart {
            background-color:#FF9900;
            border-radius:5px;
          }
          #button_reset {
            background-color:#CC3300;
            border-radius:5px;
          }
       </style>
       <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
   </head>
   <body> 
      <div><h1>KHOA DT-VT</h1></div>
      <div id="content"> 
        <div id="homecontrol" style="height:340px";>
          <div>
            <input id="ledstatus1" class="ledstatus" type="button" value="ON"/>
            <input id="ledstatus2" class="ledstatus" type="button" value="ON"/>
            <input id="ledstatus3" class="ledstatus" type="button" value="ON"/>
            <input id="ledstatus4" class="ledstatus" type="button" value="ON"/>
          </div>

           <div>
            <button class="button" onclick=getbutton(1)>Ph??ng Ng???: </button>
            <button class="button" onclick=getbutton(2)>Ph??ng Kh??ch</button>
            <button class="button" onclick=getbutton(3)>Ph??ng B???p</button>
            <button class="button" onclick=getbutton(4)>HL: </button>
          </div>

          <div>
            <button id="button_on" class="button_all" onclick="getbuttonall('on')">Turn on all</button>
            <button id="button_off" class="button_all"onclick="getbuttonall('off')">Turn off all</button>
          </div>
          <div><input class="button_setup" type="button" onclick="configurewifi()" value="Configure WiFi"/></div>
          <div>IP connected: <b><pan id="ipconnected"></pan></b></div>
        </div>
        
        <div id="wifisetup" style="height:340px; font-size:20px; display:none";>
          <div style="text-align:left; width:270px; margin:5px 25px">SSID: 
          </div>
          <div>
            <input type="text" id="ssid" placeholder="*B???t Bu???c">
          </div>
          <div style="text-align:left; width:270px; margin:5px 25px">Password: </div>
          <div>
            <input type="password" id="pass" placeholder="*B???t Bu???c">
          </div>
          <div style="text-align:left; width:270px; margin:5px 25px">Auth: 
          </div>
          <div>
            <input type="text" id="auth" placeholder="*B???t Bu???c">
          </div>
          <div>
            <button id="button_save" class="button_wifi"   onclick="writeEEPROM()">SAVE</button>
            <button id="button_restart" class="button_wifi" onclick="restartESP()">RESTART</button>
            <button id="button_reset" class="button_wifi" onclick="clearEEPROM()">RESET</button>
          </div>
          <div><input class="button_setup" type="button" onclick="backHOME()" value="Back home"/></div>
          <div id="reponsetext"></div>
        </div>
        <div>
          <input id="ledconnect" type="button">
          <div class="ledconnect_text">Connected</div>
        </div>
      </div>


      
      <div id="footer">
        <p>KMA
        </p>
      </div>




      <script>
        //-----------H??m kh???i t???o ?????i t?????ng request----------------
        function create_obj(){
          td = navigator.appName;
          if(td == "Microsoft Internet Explorer"){
            obj = new ActiveXObject("Microsoft.XMLHTTP");
          }else{
            obj = new XMLHttpRequest();
          }
          return obj;
        }
        //------------Kh???i t???o bi???n to??n c???c-----------------------------
        var xhttp = create_obj();//?????i t?????ng request cho setup wifi
        var xhttp_statusD = create_obj();//?????i t?????ng request cho c???p nh???t tr???ng th??i
        var d1,d2,d3,d4;
        var ledconnect = 1;
        //===================Kh???i t???o ban ?????u khi load trang=============
        window.onload = function(){
          document.getElementById("homecontrol").style.display = "block";
          document.getElementById("wifisetup").style.display = "none";
          getIPconnect();//G???i y??u c???u l???y IP k???t n???i
          getstatusD();//G???i y??u c???u l???y tr???ng th??i c??c ch??n ??i???u khi???n
        }
        //===================IPconnect====================================
        //--------T???o request l???y ?????a ch??? IP k???t n???i----------------------
        function getIPconnect(){
          xhttp.open("GET","/getIP",true);
          xhttp.onreadystatechange = process_ip;//nh???n reponse 
          xhttp.send();
        }
        //-----------Ki???m tra response IP v?? hi???n th???------------------
        function process_ip(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Updat data s??? d???ng javascript----------
            ketqua = xhttp.responseText; 
            document.getElementById("ipconnected").innerHTML=ketqua;       
          }
        }
        //===========C???p nh???t tr???ng th??i Led===============================
        //-----------G???i y??u c???u l???y tr???ng th??i c??c ch??n D-----------------
        function getstatusD(){
          xhttp_statusD.open("GET","/getSTATUSD",true);
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
        }
        //-----------Ki???m tra v?? nh???n response EEPROM----------------------
        function process_statusD(){
          if(xhttp_statusD.readyState == 4 && xhttp_statusD.status == 200){
            if(ledconnect == 1){
              ledconnect = 0;
              document.getElementById("ledconnect").style.background = "#222222";
            }else{
              ledconnect = 1;
              document.getElementById("ledconnect").style.background = "#00EE00";
            }
            //------Update tr???ng th??i led t??n hi???u l??n panel ??i???u khi???n----
            var statusD = xhttp_statusD.responseText;
            var obj = JSON.parse(statusD);
            d1 = obj.D1;
            d2 = obj.D2;
            d3 = obj.D3;
            d4 = obj.D4;
            updateLedstatus(d1,d2,d3,d4);
          }
        }
        //----------Hi???n th??? tr???ng th??i Led l??n tr??nh duy???t---------------------
        function updateLedstatus(D1,D2,D3,D4){
          if(D1 == "1"){
              document.getElementById("ledstatus1").value = "OFF";
              document.getElementById("ledstatus1").style.background = "red";
            }else{
              document.getElementById("ledstatus1").value = "ON";
              document.getElementById("ledstatus1").style.background = "green";
            }
            if(D2 == "1"){
              document.getElementById("ledstatus2").value = "OFF";
              document.getElementById("ledstatus2").style.background = "red";
            }else{
              document.getElementById("ledstatus2").value = "ON";
              document.getElementById("ledstatus2").style.background = "green";
            }
            if(D3 == "1"){
              document.getElementById("ledstatus3").value = "OFF";
              document.getElementById("ledstatus3").style.background = "red";
            }else{
              document.getElementById("ledstatus3").value = "ON";
              document.getElementById("ledstatus3").style.background = "green";
            }
            if(D4 == "1"){
              document.getElementById("ledstatus4").value = "OFF";
              document.getElementById("ledstatus4").style.background = "red";
            }else{
              document.getElementById("ledstatus4").value = "ON";
              document.getElementById("ledstatus4").style.background = "green";
            }
        }
        //===========T???o v?? g???i request khi ???n button============================
        //-----------Thi???t l???p d??? li???u v?? g???i request ON/OFF D4---
        function getbutton(n){
          switch (n){
            case 1:
                var ledstatus1 = document.getElementById("ledstatus1").value;
                if(ledstatus1 == "ON"){
                  xhttp_statusD.open("GET","/D1off",true);
                }else{
                  xhttp_statusD.open("GET","/D1on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 2:
                var ledstatus2 = document.getElementById("ledstatus2").value;
                if(ledstatus2 == "ON"){
                  xhttp_statusD.open("GET","/D2off",true);
                }else{
                  xhttp_statusD.open("GET","/D2on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 3:
                var ledstatus3 = document.getElementById("ledstatus3").value;
                if(ledstatus3 == "ON"){
                  xhttp_statusD.open("GET","/D3off",true);
                }else{
                  xhttp_statusD.open("GET","/D3on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 4:
               var ledstatus4 = document.getElementById("ledstatus4").value;
                if(ledstatus4 == "ON"){
                  xhttp_statusD.open("GET","/D4off",true);
                }else{
                  xhttp_statusD.open("GET","/D4on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
          }
        }
        function getbuttonall(m){
          if(m == "on"){
            xhttp_statusD.open("GET","/Allon",true);
          }else if(m=="off"){
            xhttp_statusD.open("GET","/Alloff",true);
          }
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
        }
        //===========Configure WiFi=====================================
        function configurewifi(){
          document.getElementById("homecontrol").style.display = "none";
          document.getElementById("wifisetup").style.display = "block";
        }
        //-----------Thi???t l???p d??? li???u v?? g???i request ssid v?? password---
        function writeEEPROM(){
            var ssid_get = document.getElementById("ssid").value;
            var pass_get = document.getElementById("pass").value;
            var auth_get = document.getElementById("auth").value;
            xhttp.open("GET","/writeEEPROM?ssid="+ssid_get+"&&pass="+pass_get+"&&auth="+auth_get,true);
            xhttp.onreadystatechange = process;//nh???n reponse 
            xhttp.send();
        }
        function clearEEPROM(){
          if(confirm("Do you want to delete all saved wifi configurations?")){
            xhttp.open("GET","/clearEEPROM",true);
            xhttp.onreadystatechange = process;//nh???n reponse 
            xhttp.send();
          }
        }
        function restartESP(){
          if(confirm("Do you want to reboot the device?")){
            xhttp.open("GET","/restartESP",true);
            xhttp.send();
            alert("Device is restarting! If no wifi is found please press reset!");
          }
        }
        //-----------Ki???m tra response -------------------------------------------
        function process(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Updat data s??? d???ng javascript----------
            ketqua = xhttp.responseText; 
            document.getElementById("reponsetext").innerHTML=ketqua;       
          }
        }
       //============H??m th???c hi???n ch??? n??ng kh??c================================
       //--------C???p nh???t tr???ng th??i t??? ?????ng sau 2000 gi??y----------------------
        setInterval(function() {
          getstatusD();
        },2000);
       //--------Load l???i trang ????? quay v??? Home control-------------------------
        function backHOME(){
          window.onload();
        }
       //----------------------------CHECK EMPTY--------------------------------
       function Empty(element, AlertMessage){
          if(element.value.trim()== ""){
            alert(AlertMessage);
            element.focus();
            return false;
          }else{
            return true;
          }
       }
       //------------------------------------------------------------------------
      </script>
   </body> 
  </html>
)=====";
