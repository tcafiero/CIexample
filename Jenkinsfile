pipeline {
  agent {
    node {
      label 'toolchain'
    }

  }
  stages {
    stage('Deploy') {
      parallel {
        stage('Deploy') {
          steps {
            echo 'Deploy...'
          }
        }
        stage('Test') {
          steps {
            echo 'Test...'
          }
        }
        stage('Build') {
          steps {
            echo 'Build'
            bat(returnStatus: true, script: 'compile.cmd')
          }
        }
      }
    }
  }
}