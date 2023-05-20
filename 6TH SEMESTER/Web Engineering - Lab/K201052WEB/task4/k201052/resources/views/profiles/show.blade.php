@extends('profiles.layout')

@section('content')
    <div class="row">
        <div class="col-lg-12 margin-tb">
            <div class="pull-left">
                <h2> Show Detail</h2>
            </div>
            <div class="pull-right">
                <a class="btn btn-primary" href="{{ route('profiles.index') }}"> Back</a>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-lg-12 mb-4 mt-5">
            <div class="d-flex justify-content-between align-items-center">
                <h2 class="fs-3 mb-0">User Data</h2>
            </div>
        </div>

        <div class="col-xs-12 col-sm-12 col-md-12">
            <div class="form-group">
                <label for="name"><strong>Name:</strong></label>
                <p id="name">{{ $profile->name }}</p>
            </div>
        </div>

        <div class="col-xs-12 col-sm-12 col-md-12">
            <div class="form-group">
                <label for="age"><strong>Age:</strong></label>
                <p id="age">{{ $profile->age }}</p>
            </div>
        </div>

        <div class="col-xs-12 col-sm-12 col-md-12">
            <div class="form-group">
                <label for="email"><strong>Email:</strong></label>
                <p id="email">{{ $profile->email }}</p>
            </div>
        </div>

        <div class="col-xs-12 col-sm-12 col-md-12">
            <div class="form-group">
                <label for="detail"><strong>Detail:</strong></label>
                <p id="detail">{{ $profile->detail }}</p>
            </div>
        </div>

        <div class="col-xs-12 col-sm-12 col-md-12">
            <div class="form-group">
                <label for="image"><strong>Image:</strong></label>
                <br>
                <img src="{{ asset('../../' . $profile->image) }}" alt="" width="200px">
            </div>
        </div>
    </div>
@endsection
