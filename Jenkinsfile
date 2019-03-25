pipeline {
  agent {
    node {
      label 'toolchain'
    }

  }
  stages {
    stage('Build') {
      steps {
        echo 'Build'
      }
    }
    stage('Stage') {
      steps {
        echo 'Stage'
      }
    }
    stage('Release') {
      steps {
        input(message: 'There is a candidate version, procede to release (YES or not)', ok: 'YES', id: 'tcafiero')
      }
    }
  }
}