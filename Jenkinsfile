pipeline {
  agent {
    node {
      label 'toolchain'
    }

  }
  stages {
    stage('Build') {
      parallel {
        stage('Compile') {
          steps {
            echo 'Deploy...'
          }
        }
        stage('Build') {
          steps {
            echo 'Build'
            bat(returnStatus: true, script: 'call "./Stage/Building/Build.cmd"')
          }
        }
      }
    }
    stage('Test') {
      steps {
        echo 'Test'
      }
    }
    stage('Release') {
      steps {
        echo 'Release'
      }
    }
  }
}