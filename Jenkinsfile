pipeline {
  agent {
    node {
      label 'toolchain'
    }

  }
  stages {
    timeout(time: 10, unit: 'MINUTES')
	{
    stage('Build') {
      when {
        branch 'develop'
      }
      steps {
        echo 'Build'
        bat(script: 'call "Stages\\Building\\Build.cmd"', returnStatus: true)
      }
    }
	}
    stage('Stage') {
      when {
        branch 'stage'
      }
      steps {
        echo 'Stage'
        input(message: 'There is a candidate version, procede to release', ok: 'YES', id: 'tcafiero')
      }
    }
    stage('Release') {
      when {
        branch 'master'
      }
      steps {
        echo 'Master'
      }
    }
  }
}