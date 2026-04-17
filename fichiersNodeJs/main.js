const { createApp } = Vue;

// import Home from './home.js';
// import Console from '/console.js';

//var httpServer = 'http://localhost:3000'
//var httpServer = ''

const app = createApp({
    data() {
        return {
          currentDateTime: '',
          // page: 'console',
          board: null,
          consoleDatas: "",
          pid: undefined,
          commande: "",
          status: "",
          copyright: null,
          httpServer: 'http://localhost:3000',
          // httpServer: 'http://localhost',
          // httpServer: 'http://192.168.0.8:3000',
          // httpServer: 'http://192.168.0.8',
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
        <!--div>\
          <component v-bind:is="page"></component>\
        </div-->\
      ',
    methods: {
      updateDateTime() {
        const now = new Date();
        this.currentDateTime = now.toLocaleString();
      },
    }
});

app.mount('#app');
