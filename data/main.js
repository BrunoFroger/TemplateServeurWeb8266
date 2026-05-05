const { createApp } = Vue;

// import Home from './home.js';
// import Console from '/console.js';

//var httpServer = 'http://localhost:3000'
//var httpServer = ''

const app = createApp({
    data() {
        return {
          currentDateTime: '',
          localButton: false,
          remoteButton: false,
          // httpServer: 'http://localhost:3000',
          // httpServer: 'http://localhost',
          // httpServer: 'http://192.168.0.11:3000',
          httpServer: 'http://192.168.0.11',
        }
    },
    mounted() {
      this.updateDateTime();
      setInterval(this.updateDateTime, 1000);
    },
    template: '\
        <head> \
          <meta http-equiv="Access-Control-Allow-Origin" content="*"/> \
          <meta http-equiv="Access-Control-Allow-Methods" content="GET, POST, PUT"/> \
          <meta http-equiv="Access-Control-Allow-Headers" content="Content-Type"/> \
        </head> \
        <div class="entete">\
          <table>\
            <tr>\
              <td>{{currentDateTime}}</td>\
            </tr>\
          </table>\
        </div>\
        <div>\
          <br> bonton avec fonction locale</br>\
          <button v-on:click="toggleLocalButton"> {{ localButton ? "On" : "Off" }} </button> \
        </div> \
        <div>\
          <br> bonton avec fonction en remote</br>\
          <button v-on:click="toggleRemoteButton"> {{ remoteButton ? "On" : "Off" }} </button> \
        </div> \
        <!--div>\
          <component v-bind:is="page"></component>\
        </div-->\
      ',
    methods: {
      updateDateTime() {
        const now = new Date();
        this.currentDateTime = now.toLocaleString();
      },
      toggleLocalButton() {
        this.localButton = !this.localButton;
      },
      toggleRemoteButton() {
        let requete = this.httpServer + "/toggleRemoteButton"
        fetch(requete).then(r => r.json()).then(response => {
          if (response.remoteButton == "true"){
            this.remoteButton = true;
          } else {
            this.remoteButton = false;
          }
        })
        .catch(error => {
          console.error(error);
        });
      },
    }
});

app.mount('#app');